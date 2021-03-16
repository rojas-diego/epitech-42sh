# 42SH
[![pipeline status](https://gitlab.com/rojasdiegopro/epitech-42sh/badges/master/pipeline.svg)](https://gitlab.com/rojasdiegopro/epitech-42sh/-/commits/master)
[![coverage report](https://gitlab.com/rojasdiegopro/epitech-42sh/badges/master/coverage.svg)](https://gitlab.com/rojasdiegopro/epitech-42sh/-/commits/master)

![mark](https://i.imgur.com/BpH0HnO.png)

Basic shell based on TCSH.

42sh is the end-of-first-year project for students at Epitech. While you can browse the code as much as you want, be careful about copying code from this repository if this project was assigned to you. On the other hand, you are completely free to apply the 42sh grammar we used to your own project (`local/42sh.ebnf`).

This is a group project, check the [Contributors](https://github.com/rojasdiegopro/epitech-42sh/graphs/contributors?type=a) tab and pay my talented friends a visit 😃.

## Usage

After cloning the repository, build the executable using `make`
```
$ make
```
Then you can start the shell directly by using
```
$ ./42sh [--debug-mode]
```

## Requirements

The goal was to produce a completely functional shell which could execute advanced commands and tasks.

The main features were:

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
- Combination of all of the above

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

![UI in gitlab](https://i.imgur.com/a0dvGkt.png)

### Recursive descent parsing

We used recursive descent parsing to parse and execute the user input. Our shell first tokenises the input and then parses it into a tree to be executed afterwards.
Using the `debug-mode` you can visualise the parsing of your input and how it is executed.

For example, this simple command is tokenised like so:
```sh
> ls | cat -e ; echo "2" 2> file
Word(ls) Pipe(|) Word(cat) Word(-e) Semicolon(;) Word(echo) Word("2") IO Number(2) Great(>) Word(file) EOF()
```

The language structure is defined in the [42sh Grammar](local/42sh.ebnf).

### Job control

This project implements basic job control features such as the `&` token. Commands which are ran along with this token will be executed in the background.
You can also suspend a job using `Ctrl + Z` in your terminal.

### Input processing

Preprocessing and postprocessing of the input is capital to parse advanced commands containing inhibitors, magic quotes, globbing and other advanced shell features.

### Shell shortcuts

We implemented command history, line editing and aliases into our project.
Older commands can be restablished by pressing the `Up Arrow` key.
Aliases can be set and unset to allow for efficient mapping of favourite commands.
Finally it has been made easy to edit your command on multiple line using the `ncurses` library.

## Sources

- [A complete guide to Recursive Descent Parsing](https://craftinginterpreters.com/scanning.html).
  This resources is the basis for the parsing and execution of every user input in the project.
- [Bash grammar](https://pubs.opengroup.org/onlinepubs/9699919799.2016edition/utilities/V3_chap02.html#tag_18_10).
  Consists in documentation regarding the Bash grammar and syntax. This resource was useful in understanding how shells work and was the basis for defining the 42sh   grammar
- [GNU Documentation](https://www.gnu.org/software/libc/manual/html_node/index.html).
  Probably the most comprehensive and extensive documentation source. Though dense, it provides examples and explanations on how to design primary shell features.
- [Gitlab Docs](https://docs.gitlab.com/ee/ci/pipelines/).
  Official documentation for CI development inside GitLab.
