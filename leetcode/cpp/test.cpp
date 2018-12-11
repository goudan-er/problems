#include "leetcode.h"
#include <sys/time.h>

namespace leetcode
{
struct itimerval {
	struct timeval it_interval; /* next value */
	struct timeval it_value;  /* current value */
};

struct timeval {
	long tv_sec;  /* seconds */
	long tv_usec; /* microseconds */
};

typedef int timer_id;

/**
 * The type of callback function to be called by timer scheduler when a timer
 * has expired.
 *
 * @param id  The timer id.
 * @param user_data  The user data.
 * $param len The length of user data.
 */
typedef int timer_expiry(timer_id id, void *user_data, int len);

/**
 * The type of the timer
 */
struct timer {
	LIST_ENTRY(timer) entries; /**< list entry */

	timer_id id; /**< timer id  */

	int interval; /**< timer interval(second) */
	int elapse; /**< 0 -> interval */

	timer_expiry *cb; /**< call if expiry  */
	void *user_data;  /**< callback arg */
	int len;  /**< user_data length  */
};

typedef int timer_id;

/**
 * The type of callback function to be called by timer scheduler when a timer
 * has expired.
 *
 * @param id  The timer id.
 * @param user_data  The user data.
 * $param len The length of user data.
 */
typedef int timer_expiry(timer_id id, void *user_data, int len);

/**
 * The type of the timer
 */
struct timer {
	LIST_ENTRY(timer) entries; /**< list entry */

	timer_id id; /**< timer id  */

	int interval; /**< timer interval(second) */
	int elapse; /**< 0 -> interval */

	timer_expiry *cb; /**< call if expiry  */
	void *user_data;  /**< callback arg */
	int len;  /**< user_data length  */
};

/**
 * The timer list
 */
struct timer_list {
	LIST_HEAD(listheader, timer) header; /**< list header */
	int num; /**< timer entry number */
	int max_num; /**< max entry number  */

	void (*old_sigfunc)(int); /**< save previous signal handler */
	void (*new_sigfunc)(int); /**< our signal handler  */

	struct itimerval ovalue; /**< old timer value */
	struct itimerval value;  /**< our internal timer value */
};

/**
 * Create a timer list.
 *
 * @p**
 * Create a timer list.
 *
 * @param count  The maximum number of timer entries to be supported initially.
 *
 * @return  0 means ok, the other means fail.
 */
int init_timer(int count)
{
	int ret = 0;

	if (count <= 0 || count > MAX_TIMER_NUM) {
		printf("the timer max number MUST less than %d.\n", MAX_TIMER_NUM);
		return -1;
	}

	memset(&timer_list, 0, sizeof(struct timer_list));
	LIST_INIT(&timer_list.header);
	timer_list.max_num = count;

	/* Register our internal signal handler and store old signal handler */
	if ((timer_list.old_sigfunc = signal(SIGALRM, sig_func)) == SIG_ERR) {
		return -1;
	}
	timer_list.new_sigfunc = sig_func;

	/*Setting our interval timer for driver our mutil-timer and store old timer value*/
	timer_list.value.it_value.tv_sec = TIMER_START;
	timer_list.value.it_value.tv_usec = 0;
	timer_list.value.it_interval.tv_sec = TIMER_TICK;
	timer_list.value.it_interval.tv_usec = 0;
	ret = setitimer(ITIMER_REAL, &timer_list.value, &timer_list.ovalue);

	return ret;
}


/**
 * Destroy the timer list.
 *
 * @return  0 means ok, the other means fail.
 */
int destroy_timer(void)
{
	struct timer *node = NULL;

	if ((signal(SIGALRM, timer_list.old_sigfunc)) == SIG_ERR) {
		return -1;
	}

	if ((setitimer(ITIMER_REAL, &timer_list.ovalue, &timer_list.value)) < 0) {
		return -1;
	}

	while (!LIST_EMPTY(&timer_list.header)) { /* Delete. */
		node = LIST_FIRST(&timer_list.header);
		LIST_REMOVE(node, entries);
		/* Free node */
		printf("Remove id %d\n", node->id);
		free(node->user_data);
		free(node);
	}

	memset(&timer_list, 0, sizeof(struct timer_list));

	return 0;
}

/**
 * Add a timer to timer list.
 *
 * @param interval  The timer interval(second).
 * @param cb  When cb!= NULL and timer expiry, call it.
 * @param user_data Callback's param.
 * @param len The length of the user_data.
 *
 * @return  The timer ID, if == INVALID_TIMER_ID, add timer fail.
 */
timer_id add_timer(int interval, timer_expiry *cb, void *user_data, int len)
{
	struct timer *node = NULL;

	if (cb == NULL || interval <= 0) {
		return INVALID_TIMER_ID;
	}

	if (timer_list.num < timer_list.max_num) {
		timer_list.num++;
	} else {
		return INVALID_TIMER_ID;
	}

	if ((node = malloc(sizeof(struct timer))) == NULL) {
		return INVALID_TIMER_ID;
	}
	if (user_data != NULL || len != 0) {
		node->user_data = malloc(len);
		memcpy(node->user_data, user_data, len);
		node->len = len;
	}

	node->cb = cb;
	node->interval = interval;
	node->elapse = 0;
	node->id = timer_list.num;

	LIST_INSERT_HEAD(&timer_list.header, node, entries);

	return node->id;
}

/* Tick Bookkeeping */
static void sig_func(int signo)
{
	struct timer *node = timer_list.header.lh_first;
	for (; node != NULL; node = node->entries.le_next) {
		node->elapse++;
		if (node->elapse >= node->interval) {
			node->elapse = 0;
			node->cb(node->id, node->user_data, node->len);
		}
	}
}
};