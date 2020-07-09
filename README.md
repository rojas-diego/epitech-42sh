# 42SH

![mark](https://i.imgur.com/BpH0HnO.png)

Basic shell based on TCSH.

42sh is the end-of-year project for students at Epitech during their first year. Please, while you can skim through the codebase as much as you want, don't use any of the code directly if this project was given to you. On the other hand you are free to use the `local/42sh.ebnf` file and apply it to your project.

## Usage

After cloning the repository, build the executable as so
```
$ make
```
Then you can start the shell directly by using
```
$ ./42sh [--debug-mode]
```

## Requirements

The objective was to produce a completely functional shell which could execute advanced commands and tasks.

The main point of focuses were the following:

- Basic command execution `ls`, `cd`, `make`.
- Argument parsing `ls -l`
- Redirections `ls >> file`, `ls < file`
- Separators `ls ; cd ~`
- Builtins `cd`, `echo`, `env`, `unsetenv`, `setenv`...
- Pipes `ls | grep "include"`
- Inhibitors `ls "this is a\" valid string"`
- Globbing `ls *.a`
- Job control
- Subshells `(ls -l)`
- Control statements `if`, `while`, `repeat`, `else if`, `else`, `foreach`
- Advanced manipulations and commands `cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo “OK”`
- Scripting `./ftest.sh`
- Variables and state `var i`

In the end, the shell was expected to execute complete scripts like the following.
```sh
if (0) then
    echo "1!"
else if (0) then
    echo "2!"
else
    cd doesnt_exist || ls -l | grep . | grep a ; echo "Done!" > file
endif

ls &
cat script.sh && ps
repeat 10 echo "10"
```

## Features

### CI Workflow

Post project completion, we used [GitLab](https://docs.gitlab.com/) to introduce CI pipelines. They can be seen at the top of the repository.
The pipeline can be found [here](.gitlab-ci.yml).

It allows us to automatically run our [functional tests](ftest.sh) as well as our [unit tests](Makefile), upon pushing to the GitLab remote.

## Sources

- [A complete guide to Recusrive Descent Parsing](https://craftinginterpreters.com/scanning.html).
  This resources is the basis for the parsing and execution of every user input in the project.
- [Bash grammar](https://pubs.opengroup.org/onlinepubs/9699919799.2016edition/utilities/V3_chap02.html#tag_18_10).
  Consists in documentation regarding the Bash grammar and syntax. This resource was useful in understanding how shells work and was the basis for defining the 42sh   grammar
- [GNU Documentation](https://www.gnu.org/software/libc/manual/html_node/index.html).
  Probably the most comprehensive and extensive documentation source. Though dense, it provides examples and explanations on how to design primary shell features.
- [Gitlab Docs](https://docs.gitlab.com/ee/ci/pipelines/).
  Official documentation for CI development inside GitLab.
