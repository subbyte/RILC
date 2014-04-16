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
| [arguments]     | & exit()      |
| return addr     | & system()    |
| frame pointer   | ............. |
| [local vars]    | ............. |
| ............... | ............. |
| (low address)   | (low address) |


#### Exploit Prerequisites

- turn off ASLR (root):
```bash
sysctl -w kernel.randomize_va_space=0
```
- turn off stack guard when compiling: -fno-stack-protector
- NO need to turn off execstack when compiling (no code on stack in RILC)


#### How to get "/bin/sh"

Declare an environment variable:
```bash
export VARSHELL="     /bin/sh"
```
- beginning spaces are very important to locate "/bin/sh" in the future.
- use gdb to locate the exact address of "/bin/sh".
- debug your exploit with strace.


#### Trace the Exploit
Using SystemTap to trace function/library/system calls:
```bash
stap -v tracing.stp vulp -o tracefile
```


#### Tested Environments
The demonstration package is tested successful on Fedora 19
