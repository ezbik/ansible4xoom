
Before run install roles locally:

    ansible-galaxy install -r ./requirements.yml;

Edit Hosts list:
    ./hosts

Main run (apply to all servers per their roles) [1]:
    ansible-playbook ./xoom.security.yml

Apply only to 2 servers:
    ansible-playbook ./xoom.security.yml -l cdn:cdntest

Add an IP to firewall:
    - edit ./roles/xoom.firewall/templates/firewall.sh.j2
    - do [1]
