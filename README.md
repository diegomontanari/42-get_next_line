# 42-get_next_line
In this project, we will learn:

- What static variables are,  
- How files are opened, read, and closed in an OS,  
- How files are interpreted by a programming language.  

**NOTE:** Since this is a 42 school project, I must follow their norm.  

## Example of Interpretation in a Programming Language  

When a language like Python or C opens a text file, it reads a sequence of encoded characters (e.g., in UTF-8 or ASCII). If it were a binary file (such as an image or an executable file), the program would have to decode it differently.  

If you want to return one line at a time from a text file, you can write a function that uses sequential reading. For example, in Python:  

```python
def get_next_line(file_path):
    with open(file_path, "r") as file:
        for line in file:
            yield line.strip()  # Returns one line at a time without the newline character

file_reader = get_next_line("text.txt")
print(next(file_reader))  # Prints the first line  
print(next(file_reader))  # Prints the second line  
```

In today's project, we will do exactly this but in the C language.  

## Static Variables  

First of all, we need to understand what Static Variables are. As you know, local variables exist only within the scope of the function they belong to.  

Referring to a variable `x` outside the function in which `x` was defined is equivalent to initializing a new variable (this does not cause compilation errors but can lead to various bugs and unexpected behaviors), while working with a variable that does not exist because it is limited to an internal function will result in a compilation error.  

This is a static variable:  

```c
char *get_next_line(int fd)
{
    static char *buffer;
    // ... rest of the function
}
```

## Let's Start with the Code  

We begin with the main program, `get_next_line.c`.  

First, we need to write the function:  

```c
char *get_next_line(int fd)
```

The text is not yet complete as I still need to finish it.

