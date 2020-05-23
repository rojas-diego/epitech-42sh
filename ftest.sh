#!/bin/bash

TESTS_PATH=tests/ftests

mkdir $TESTS_PATH 2> /dev/null

NB_TEST_PASSED=0
NB_TEST_FAILED=0
RED='echo -ne \033[38;2;255;50;50m'
GREEN='echo -ne \033[38;2;50;255;50m'
WHITE='echo -ne \033[0m'

function _test () {
    echo -ne "$1" | $2 ./42sh 2>&1 | cat > $TESTS_PATH/$3_42sh.ftest
    echo -ne "$1" | $2 tcsh 2>&1 | cat > $TESTS_PATH/$3_tcsh.ftest
    difference=`diff $TESTS_PATH/$3_42sh.ftest $TESTS_PATH/$3_tcsh.ftest`
    result=$?
    if [ $result = 0 ]
    then
        $GREEN
        echo $4 OK
        $WHITE
        NB_TEST_PASSED=$((NB_TEST_PASSED+1))
    else
        $RED
        echo "$4 KO, $TESTS_PATH/$3_42sh.ftest and $TESTS_PATH/$3_tcsh.ftest differ"
        $WHITE
        NB_TEST_FAILED=$((NB_TEST_FAILED+1))
        echo $difference > $TESTS_PATH/$3_diff.ftest
    fi
}

_test '/bin/ls' "env -i" ls "Basic test ls"
_test '/bin/cd ..\n/bin/ls' "env -i" cd "Basic test cd"
_test 'setenv' "env -i" env      "Basic test env"
_test 'setenv MDR 100\nsetenv | /usr/bin/grep MDR' "env -i" setenv "Basic test setenv"
_test 'unsetenv PATH\nsetenv | /usr/bin/grep PATH' "" unsetenv "Basic test unsetenv"
_test 'alias this_is_an_alias b && alias | grep this_is_an_alias' ""       alias "Basic test alias"
_test 'repeat 5 /bin/ls' "env -i" repeat "Basic test repeat"
_test 'if (1) /bin/ls' "env -i" if "Basic test if"
_test 'foreach f (1 2 3)\necho 1 + $f\nend\n' "" foreach "Basic test foreach"
_test '/bin/ls > ls_output\n/bin/cat ls_output\n/usr/bin/rm ls_output' "" simple_right_redir "Basic test simple right redir"
_test '/bin/ls >> ls_output\n/bin/ls >> ls_output\n/bin/cat ls_output\n/usr/bin/rm ls_output' "" double_right_redir "Basic test double right redir"

$GREEN
echo "Test passed: $NB_TEST_PASSED"
$RED
echo "Test failed: $NB_TEST_FAILED"
$WHITE
