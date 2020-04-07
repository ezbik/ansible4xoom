
Before run install roles locally:

    ansible-galaxy install -r ./requirements.yml;

Main run [1]:
    ansible-playbook ./xoom.security.yml

Hosts list:
    ./hosts

Add an IP to firewall:
    - edit ./roles/xoom.firewall/templates/firewall.sh.j2
    - do [1]

