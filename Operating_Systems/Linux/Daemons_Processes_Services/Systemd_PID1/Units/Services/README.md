## Service unit
- **What?** Service units have a .service extension and represent system services. [Listing services](/Operating_Systems/Linux/Administration/Commands/systemctl)
- *Dependent services:* A Service may be dependent on 0 or more services, stopping/restarting 1 may require start/stop others also. [# systemctl list-dependencies](/Operating_Systems/Linux/Administration/Commands/systemctl)
- *Masking Services:* A system may have conflicting services installed. Eg: iptables, firewalld. Masking service means if service is started by mistake nothing will happen. [#systemctl mask](/Operating_Systems/Linux/Administration/Commands/systemctl)

