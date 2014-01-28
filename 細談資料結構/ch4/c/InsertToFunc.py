#! /usr/bin/python
# -*- coding: utf-8 -*-

import os
import sys

def InsertToFunc(lines, funcLines):
    #print lines
    print funcLines

    for i in funcLines:
        for j in range(i-1, len(lines)):
            if str(lines[j]).find('{') != -1:
                if str(lines[j]).find('}') != -1:
                    break
                lines.insert(j+1, '\t::printf ("This is line %d of file %s (function %s)\\n", __LINE__, __FILE__, __func__);\n')
                break

    return lines

def main():
    FileName = sys.argv[1]
    print FileName
    os.system("ctags-exuberant -x " + FileName + " | ack -o 'function\s+.*' | ack -o '\d+\s+.*' | ack -o '^\d+\s+' | sort -k 1 -nr > /tmp/test.txt")

    f = open('/tmp/test.txt', 'r+')
    #funcLines = map(int, funcLines)
    funcLines = [int(i)for i in f.read().splitlines()]
    f.close()

    f = open(str(FileName), 'r+')
    lines = [i for i in f.read().splitlines()]
    f.close()

    InsertListfinish = InsertToFunc(lines, funcLines)

    newfile = open(str(FileName), "w+")
    newfile.truncate()

    for l in InsertListfinish:
        newfile.write(l + '\n')
        #print repr(l)
        #print l

    newfile.close()

if __name__=='__main__':
    if len(sys.argv) > 1:
        main()
    else:
        pass
        print "please input python test.py filename"
