# Confirm
Simple program that when run as
```
$ ./confirm [command] [arguments]
```
will ask the user to confirm their decision to run the command before execution.

Create an alias with
```
alias [command]="/path/to/confirm command"
```
in `~/.bashrc` and run
`source ~/.bashrc` or restart terminal session to use the alias.
If you would like to also use this alias with `sudo`, add the following before any other aliases
```
alias sudo="sudo "
```
to your `~/.bashrc` file. Do not forget to run `source ~/.bashrc` after adding the sudo alias.
### Why use this?
`rm -rf` exists.