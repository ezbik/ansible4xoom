
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

Add Nginx+SSL
    - define a new host like this in `hosts` file. You can use either ssltype=fake or ssltype=letsencrypt. If fake, then self-signed SSL is issued:

        hostAAA111     ansible_host=x.x.x.x.x ssltype=fake         backend=http://127.0.0.1:4000  domains_list='["cdntest.xoomtv.net"]'
        hostBBB222     ansible_host=x.x.x.x.x ssltype=letsencrypt  backend="http://127.0.0.1:4000" domains_list='["cdn1.xoomtv.net"]'


