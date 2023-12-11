# Confirm
Simple program that when run as
```
$ ./confirm [command] [arguments]
```
will ask the user to confirm their decision to run the command before execution.

Create an alias with
```
$ alias [command]="/path/to/confirm command"
```
in `~/.bashrc` and run
`$source ~/.bashrc`