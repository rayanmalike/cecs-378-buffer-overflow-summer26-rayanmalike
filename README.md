# Buffer Overflow: Vulnerable vs Secure
# lab 3: Rayan Ezedin

## Description
This project demonstrates a stack-based buffer overflow vulnerability in C and how to defend against it. This was written as an alternative to the standard Lab 3 assignment

## Files
- `vulnerable.c`: intentionally an unsafe program using strcpy with no bounds checking
- `secure.c`: the fixed version using strncpy and input length validation
- `writeup.md`: the full explanation of the vulnerability, testing, and the fix

## How to Run

**Vulnerable:**
```bash
gcc -o vulnerable vulnerable.c
./vulnerable "hello"
./vulnerable $(python3 -c "print('A' * 100)")
```

**Secure:**
```bash
gcc -o secure secure.c
./secure "hello"
./secure $(python3 -c "print('A' * 100)")
```

## Pledge
I would like to thank Professor Giacalone for allowing me to explore this independently for Lab 3. Getting to build something from scratch instead of following a guided lab actually helped 
me understand buffer overflows a lot better than I expected