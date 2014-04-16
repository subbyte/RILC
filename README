RILC
====

return-into-libc demonstration

Description of RILC: https://speakerdeck.com/subbyte/the-evolution-of-stack-control-flow-attacks


Stack Overwritten:

    before                  after
            (high address)
.................   ......................
.................   [pointer to "/bin/sh"]
.................   [pointer to exit()   ]
[ret (saved EIP)]   [pointer to system() ]
[saved registers]   ......................
[local vars     ]   ......................
.................   ......................
            (low address)


Prerequisites:
- turn off ASLR: # sysctl -w kernel.randomize_va_space=0
- turn off stack guard when compiling: -fno-stack-protector
- NO need to turn off execstack (no code on stack in RILC)


How to get "/bin/sh":
We declare a environment variable for demonstration purposes.
    $ export VARSHELL="     /bin/sh"
Space is very important to locate "/bin/sh" right in the future.
Read exploit.c for more details.
Use strace to debug if your exploit does not succeed.


Using SystemTap to trace function/library/system calls:
    $ stap -v tracing.stp vulp -o tracefile


The demonstration package is tested successful on Fedora 19
