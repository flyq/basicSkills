from mininet.topo import Topo

class MyTopo(Topo):
    def __init__(self):
        Topo.__init__(self)
        host1 = self.addHost('h1')
        host2 = self.addHost('h2')
        host3 = self.addHost('h3')
        host4 = self.addHost('h4')

        switch1 = self.addSwitch('s1')

        self.addLink(host1,switch1)
        self.addLink(host2,switch1)
        self.addLink(host3,switch1)
        self.addLink(host4,switch1)

topos = {'mytopo':(lambda:MyTopo())}
