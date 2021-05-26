## Samba Bugs
- **1. Wannacry/Ransomeware(May-2017)**    
  - Clone of ETERNALBLUE (14-April-2017) CVE-2017-0144. 
  - More Details: https://www.endgame.com/blog/technical-blog/wcrywanacry-ransomware-technical-analysis
  - ETERNALBLUE: vulnerability in Microsoft's-SMBv1 allowing execution of remote excitable file.
```c
                         Connected on Net
                        (SMBv1 Microsoft Server)port=445                                     Hacker
                                                                 <-------NegoProtReq-------
                                                                 -------NegoProtRes------>
                                                                 <-------SessSetUpReq-------
                                                                 -------SessSetUpRes------>
                                                                 <-------TreeConnReq-------
                                                                  -------TreeConnRes------>
                                                   <---Transaction_Req(payload = a.exe(virus))--        
     if payload has checksum,Execute payload
                                                    --- Transaction_Res-->                          
                       // User open Personal Files >Virus Alerts (Give me Money)
                         Give $300 now, if not paid by 3-days doubled Amount $600
                         After 7 days if unpaid, all files would be deleted
```                         
  - HOW PREVENTED? 
    - Install security updates released by Microsoft, Huchin created process to slow the virus. RHEL-5,6 supports SMBv1(where malware patch is already applied), RHEL-7 supports SMBv2,3 which are not affected by this malware.
- **2. BADLOCK:** 
  - Bug in DCE-RPC. Microsoft AD uses  SAMR, LSA which are based on DCE 1.1. This DOS+MITM between AD & Samba(on RHEL)
- **3. SMB SIGNING DISABLED:**  
  - Signing is disabled on samba server(RHEL or Microsoft) and hence MIM attack can be achieved. Attacker inject data into the session without detection. 
  - Successful exploitation could allow remote attackers to gain sensitive information.    
  - SOLUTION? Enforce message signing on samba server. On Samba, the setting is called ‘server signing’.
