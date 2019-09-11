# C reasonably fast linked-list

Single linked list shared library.
Quite fast.

Well suited for embedded processors with limited power.

## compile

Requires:
* cmake version >= 3.0
* gcc >= 4.4

```bash
cmake .
make
```
to reset build and start from scratch:

`./init_all.sh`

The test executable is `listtest`.

## TODO

* Preallocate a predefined number of nodes for faster operations.
* Limit the number of nodes at creation.

## license

Copyright JBPlinn - 2019
