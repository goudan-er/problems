package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"regexp"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)
	writer := bufio.NewWriterSize(os.Stdout, 1024*1024)

	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	linkPattern := "<a .*?href=\"(.*?)\".*?>(.*?)</a>"
	linkRegexp := regexp.MustCompile(linkPattern)
	titlePattern := "<.*?>"
	titleRegexp := regexp.MustCompile(titlePattern)

	for i := int32(0); i < n; i++ {
		html := readLine(reader)
		links := linkRegexp.FindAllStringSubmatch(html, -1)
		for _, link := range links {
			fmt.Fprintf(writer, "%s,%s\n", link[1], strings.TrimSpace(
				titleRegexp.ReplaceAllString(link[2], "")))
		}
	}

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
