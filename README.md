# C reasonably fast linked-list

Single linked list shared library.
Quite fast.

Well suited for embedded processors with limited power.

## compile

```bash
cmake .
make
```

The test executable is `listtest`.

## TODO

* Preallocate a predefined number of nodes for faster operations.
* Limit the number of nodes at creation.

## license

Copyright JBPlinn - 2019
