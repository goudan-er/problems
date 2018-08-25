package leetcode

import "strconv"

func letterCombinations(digits string) []string {
	ret := []string{}

	dialKey := map[int]string{
		2: "abc",
		3: "def",
		4: "ghi",
		5: "jkl",
		6: "mno",
		7: "pqrs",
		8: "tuv",
		9: "wxyz",
	}

	if len(digits) == 0 {
		return ret
	}

	ret = append(ret, "")
	for _, d := range digits {
		key, err := strconv.Atoi(string(d))
		if err != nil {
			panic(err)
		}
		tmpRet := []string{}
		for _, s := range ret {
			for _, c := range dialKey[key] {
				tmpRet = append(tmpRet, s+string(c))
			}
		}
		ret, tmpRet = tmpRet, ret // maybe can do some optimization, like using c++ move
	}

	return ret
}
