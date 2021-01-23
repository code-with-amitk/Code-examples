## EBS(Elastic Block Storage)
  - allows to create persistent block level storage volumes and attach it to EC2 instances.
  - Once attached you can create a file system on top of these volumes, run a database
  
### EBS Use Cases
  - OS - Used for Boot/Root Volume, secondary Volumes
  - Databases – Scales with your performance needs
  - Enterprise applications – Provides reliable block storage to run mission-critical applications
  - Business continuity – Minimize data loss and recovery time by regularly backing up using EBS Snapshots
  - Applications – Install and persist in any application.  
  
### RAID(Redundant Array of Independent Disks)
  - RAID is putting a whole bunch of disks together and they act as one disk.
  - Raid 0: Striped, No redundancy, good performance
  - Raid 1: Mirrored, Redundancy
  - Raid 5: Good for reads, bad for writes, AWS does not recommend putting raid 5 on EBS
  - Raid 10: Striped mirrored, Good redundancy and Good performance
