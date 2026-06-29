#buffer overflow: Vulnerable vs Secure

##Main Overview
so for this project, I wrote two C programs in order to demonstrate a buffer overlow vulnerability and how to fix it. One is intentionally brokn while the other handles the same input safely

##The Vulnerability (vulnerable.c)
main issue with this is strcpy in which it copies input into a 64 byte buffer with no size check on it. For example, if the input is longer than that, it overwrites memory past the buffer on that stack.

Furthermore, there is also a secret() function in the code that never actually gets called. In a real attack for example, an overflow like this could potentially be used to redirect execution to some place unintentiinally, like that function or an injected shellcode

##Testing Overflow
command to trigger crash:

```bash
gcc -o vulnerable vulnerable.c
./vulnerable $(python3 -c "print('A' * 100)")
```
Output:
```
Trace/BPT trap: 5
```

On a Linux system, it would segfault. On my Mac howeverm it threw a Trace/BPT trap. Did some research and figured out its practically the same idea in which the stack got corrupted. 

##Solution (secure.c)
in order to fix it, I replaced strcpy with strncpy which limits how many bytes get copied into the buffer. I also added an input length check before the buffer gets touched so if an input if 64 characters +, the program rejects it immediatly

essentially its two layers of defense. Either one could help but having both makes it more solid.

##Testing the Fix
```bash
gcc -o secure secure.c
./secure $(python3 -c "print('A' * 100)")
```
Output:
Error: input too long, max 63 charactrs

so instead of crashing, it just prints an error and exits cleanly. This means the overflow actually never happens.

##Main Takeaway
The main takeaway I got from this lab was that the vulnerable version shows how easy it is to write an unsafe C code when you dont think about memory. strcpy is in the standard library and works fine for normal input. The problem only occurs when you throw something unexpected at it. However, the fix isnt complicated, it just requires being deliberate about how much data you are actually allowing in the program. 