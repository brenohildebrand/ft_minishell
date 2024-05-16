# Bringing proceduralism to C

This is an attempt of applying what I've seen in Houdini in this project.

Here is how it works.

The code will be composed by nodes. These nodes will be independent. They each receive inputs (at most 4) and they output something (only 1 thing). By combining them we'll end up with a graph that solves our problem.

The workflow will be as follows.

```c
t_minishell	mini;

while (42)
{
	input(); // the input node will receive and generate
	
}
```