## cat command:

- we usually use this command to view the content of the file.

- reading multiple files:

```
cat file1 file2 file3
```

- reading multiple files one by one:

```
cat file1; cat file2; cat file2
```

- using cat to combine two files content into one file:

```
cat file1 file2 > combined_result.txt
```

- overwriting content via cat command, the command will overwrite the
  content of the file:

```
cat /etc/passwd > file.txt
```

- appending content via cat command:

```
cat /etc/passwd >> file.txt
```

- in the cat interactive mode to insert the data, you can use EOF
  to exit out or stop editing the file content, with pressing `Ctrl + C` or
  `Ctrl + D`.

```
cat << EOF >> test_file.txt
```

- viewing content with line number using cat:

```
cat -n file.txt
```

- for viewing the content with line number and end of line indication.

```
cat -ne file.txt
```

- for removing the multiple blank lines with cat:

```
cat -s file.txt
```

## nano text editor:

- Simple cli text editor just like a notepad (windows default text editor software),
  you have option to edit text in buffer.

- For saving the data, press `Ctrl+O`

- For exiting the file, press `Ctrl+X`

- For cutting the line, press `Ctrl+K`

- For pasting the line, press `Ctrl+U`
