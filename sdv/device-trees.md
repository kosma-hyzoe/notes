# Device trees

* [Basic syntax specs](https://www.devicetree.org/specifications)
* `Documentation/devicetree/bindings`
* [Design principles](https://youtu.be/Nz6aBffv-Ek?t=1739)

* `.dtsi` files are included in a final `.dts` file. `dtc` only compiles `.dts`.
* `.dtsi` commonly used for SoC-level info, `.dts` for board-level info TODO
* can overwrite devices from `.dtsi` in `.dts` by &device name or rewriting the
device with a new property [like this](https://youtu.be/Nz6aBffv-Ek?t=1108)
* no `/sys/firmware/devicetree`?

* `fdt` - "flatten device tree", additional U-Boot DT patching.
* device tree overlay - small dt snppet, i.e. to describe additional devices
  in an expansion board. supported in uboot, not in linux.


* `make dt_bindings_check` - check YAML bindings
* `make dtbs_check` - validate DTs against the yaml bindings

* can use `#define` for human readable definitions

* 32 bit integers as a cell, 64 bit integers as two cells
* `address-cells` and `#size-cells` - how many cells are used in sub-nodes to
encode the address and size in the `reg` property. same goes with
`interrupt-cells` etc.


`<prop>-names` pattern:

```dt
interrutps 			= <0 59 0>, <0 70 0>;
interrupts-names	= "macirq", "macpmt";
```
