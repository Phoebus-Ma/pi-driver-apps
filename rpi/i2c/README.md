
# Examples

- at24c02


# Configuration

On raspbian:

```bash
$ sudo raspi-config
```

Trun on i2c iterface:

```bash
--> 3 Interface Options    Configure connections to peripherals
    --> I5 I2C         Enable/disable automatic loading of I2C kernel module
        --> <Yes>
```

original:

```bash
$ ls /dev/i2c*
/dev/i2c-2
```

turn on i2c:

```bash
$ ls /dev/i2c*
/dev/i2c-1  /dev/i2c-2
```

The `/dev/i2c-1` is test object.
