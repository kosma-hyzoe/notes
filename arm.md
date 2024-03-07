# arm

## GIC V3/V4

* SPI - shared peripheral, any core
* PPI - private, one core (i.e. generic timer)
* SGI - software generated, inter-PE, has an SGI register
* LPI - locality-specific,

States:
* Inactive
* Pending (not acknowledged by PE)
* Active - acknowledged by PE
* Active and pending - acknowledged,  another instance is pending

Secure groups:
* Secure 0 - EL3, FIQ only
* Secure 1 - EL1
* Non-secure 1 - non-secure, OS/Hypervisor

* `GICD_` - distributor, memory mapped registers for basic SPI config
* `GICR_` - redistributor, one per core. SGI, PPI, LPI
* CPU interfaces (`ICC_*_ELn`) - interrupt hadling
