RILC
====

return-into-libc demonstration

Description of RILC: https://speakerdeck.com/subbyte/the-evolution-of-stack-control-flow-attacks


#### Stack Overwritten Structure
| before          | after         |
| :-------------: | :-----------: |
| (high address)  | (high address)|
| ............... | ..............|
| ............... | & "/bin/sh"   |
| arguments       | & exit()      |
| return addr     | & system()    |
| frame pointer   | ............. |
| local vars      | ............. |
| ............... | ............. |
| (low address)   | (low address) |


#### Exploit Prerequisites

- turn off ASLR (root):
```bash
sysctl -w kernel.randomize_va_space=0
```
- turn off stack guard when compiling: -fno-stack-protector.
- find the addresses of library calls `system()` and `exit()`.
- find the address of string "/bin/sh" as an argument for `system()`.
- NO need to turn off execstack when compiling (no code on stack in RILC).


#### How to get "/bin/sh"

Create the string by declaring an environment variable (for demonstration purpose):
```bash
export VARSHELL="     /bin/sh"
```
- every process created by the shell now has the string.
- use gdb to locate the exact address of "/bin/sh".
- beginning spaces make it easy to locate exact "/bin/sh".
- debug your exploit with strace.


#### Trace the Exploit
Using SystemTap to trace function/library/system calls:
```bash
stap -v tracing.stp vulp -o tracefile
```


#### Tested Environments
The demonstration package is tested successful on Fedora 19.
