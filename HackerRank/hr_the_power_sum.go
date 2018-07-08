package leetcode

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
	"strings"
)

func power(a int32, b int32) int32 {
	return int32(math.Pow(float64(a), float64(b)))
}

func powerSumHelper(target int32, N int32, start int32) int32 {
	if target == 0 {
		return 1
	} else if N == 0 {
		return 0
	} else {
		var ret int32
		for next, nextN := start, power(start, N); nextN <= target; nextN = power(next, N) {
			ret += powerSumHelper(target-nextN, N, next+1)
			next++
		}
		return ret
	}
}

// Complete the powerSum function below.
func powerSum(target int32, N int32) int32 {
	return powerSumHelper(target, N, 1)
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
	checkError(err)

	defer stdout.Close()

	writer := bufio.NewWriterSize(stdout, 1024*1024)

	XTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	X := int32(XTemp)

	NTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	N := int32(NTemp)

	result := powerSum(X, N)

	fmt.Fprintf(writer, "%d\n", result)

	writer.Flush()
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err != nil {
		panic(err)
	}
}
