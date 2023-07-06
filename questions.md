# Questions

* object code (... vs llvm?)
* big vs little endian
* ...why format partitions after creating?

```
    pl061@9030000 {
        phandle = <0x8002>;
        clock-names = "apb_pclk";
        clocks = <0x8000>;
        interrupts = <0x00 0x07 0x04>;
        gpio-controller;
        #gpio-cells = <0x02>;
        compatible = "arm,pl061\0arm,primecell";
        reg = <0x00 0x9030000 0x00 0x1000>;
        status = "disabled";
    };
    chosen {
        #size-cells = <0x00000001>;
        #address-cells = <0x00000001>;
        stdout-path = "
```
