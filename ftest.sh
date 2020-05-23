#!/bin/bash

TESTS_PATH=tests/ftests

mkdir $TESTS_PATH 2> /dev/null

NB_TEST_PASSED=0
NB_TEST_FAILED=0
RED='echo -ne \033[38;2;255;50;50m'
GREEN='echo -ne \033[38;2;50;255;50m'
WHITE='echo -ne \033[0m'

function _test () {
    echo -ne $1 | ./42sh 2>&1 | cat > $TESTS_PATH/$2_42sh.ftest
    echo -ne $1 | tcsh 2>&1 | cat > $TESTS_PATH/$2_tcsh.ftest
    difference=`diff $TESTS_PATH/$2_42sh.ftest $TESTS_PATH/$2_tcsh.ftest`
    result=$?
    if [ $result = 0 ]
    then
        $GREEN
        echo $3 OK
        $WHITE
        NB_TEST_PASSED=$((NB_TEST_PASSED+1))
    else
        $RED
        echo "$3 KO, $TESTS_PATH/$2_42sh.ftest and $TESTS_PATH/$2_tcsh.ftest differ"
        $WHITE
        NB_TEST_FAILED=$((NB_TEST_FAILED+1))
        echo $difference > $TESTS_PATH/$2_diff.ftest
    fi
}

_test "ls" ls "Basic test ls"
_test "cd ..\nls" cd "Basic test cd"
_test "env" env "Basic test env"
_test "setenv MDR=100\nenv" setenv "Basic test setenv"
_test "unsetenv PATH\nenv" unsetenv "Basic test unsetenv"

$GREEN
echo "Test passed: $NB_TEST_PASSED"
$RED
echo "Test failed: $NB_TEST_FAILED"
$WHITE
