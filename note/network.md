# Network note

## Useful tools
```
nc
```

## Check Net Status

Wifi
```
sudo iwconfig
```

nmcli ( network managment command line interface)
```
nmcli connection show
```

## DNS
Check DNS status
```
resolvectl status
```

To setup DNS, one's should check systemd-resolved daemon. Configuration files for systemd are called unit files and are stored in /etc/systemd/system/, /run/systemd/system/, and /lib/systemd/system/.
Side note about systemd & systemctl: systemd is the comprehensive system and service manager responsible for a wide range of system tasks, running in the background as part of the operating system.
systemctl is the command-line tool used to control systemd, providing a way for users and administrators to manage services and system states interactively.
```
sudo vim /run/systemd/resolve/stub-resolv.conf #Change the nameserver to 8.8.8.8
sudo ln -sf /run/systemd/resolve/stub-resolv.conf /etc/resolv.conf
```

Restart the deamon
```
sudo systemctl restart systemd-resolved.service 
sudo systemctl status systemd-resolved.service 
```

Use dig or nslookup to check the DNS current
```
dig google.com
nslookup google.com
```

Install bind9
```
sudo apt install bind9
```
