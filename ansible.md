# Ansible

* ` ansible all --key-file ~/.ssh/ansible_ed25519 -i main.yaml -m ping`
* `-f 1` - non-parallel, default 5
* `ansible db -b -m mysql_user -a "name=django host=% password=12345 \
priv=*.*:ALL state=present"`

* synchronize, rsync
* copy, fetch (flat=yes)
