#buffer overflow: Vulnerable vs Secure

##Main Overview
so for this project, I wrote two C programs in order to demonstrate a buffer overlow vulnerability and how to fix it. One is intentionally brokn while the other handles the same input safely

##The Vulnerability (vulnerable.c)
main issue with this is strcpy in which it copies input into a 64 byte buffer with no size check on it. For example, if the input is longer than that, it overwrites memory past the buffer on that stack.

Furthermore, there is also a secret() function in the code that never actually gets called. In a real attack for example, an overflow like this could potentially be used to redirect execution to some place unintentiinally, like that function or an injected shellcode

##Testing Overflow
Output when it crashes:

```bash
gcc -o vulnerable vulnerable.c
./vulnerable $(python3 -c "print('A' * 100)")
```

On a Linux system, it would segfault. On my Mac howeverm it threw a Trace/BPT trap. Did some research and figured out its practically the same idea in which the stack got corrupted. 