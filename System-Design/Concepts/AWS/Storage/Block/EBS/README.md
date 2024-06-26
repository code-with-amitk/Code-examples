**EBS / Elastic Block Storage**
- [Backup of Data/Snapshots](#bu)
- [EBS Use Cases](#uc)
- [RAID(Redundant Array of Independent Disks)](#raid)
- [EBS vs EFS](/System-Design/Concepts/AWS/Storage/File/EFS#vs)

## EBS
- This is solid state persistent/permanent block level storage volumes(ie hard disks) & can be attached to EC2 instances.
- Stores data in Single Availabilty zone. Both EC2 and EBS volume should be in same Availabilty zone.

<a name=bu></a>
### Backup of Data (called snapshot)
- We can take backup of data present on EBS. Each backup is called Snapshot. Snapshots are stored on [S3](/System-Design/Concepts/AWS/Storage/Object_Store/S3/)
- Snapshots are incremental, ie data which is changed between snapshots are only stored not complete data again.
<img src=ebs_snapshots.JPG width=500 />

<a name=uc></a>
### EBS Use Cases
  - OS - Used for Boot/Root Volume, secondary Volumes
  - Databases – Scales with your performance needs
  - Enterprise applications – Provides reliable block storage to run mission-critical applications
  - Business continuity – Minimize data loss and recovery time by regularly backing up using EBS Snapshots
  - Applications – Install and persist in any application.  

<a name=raid></a>
### RAID(Redundant Array of Independent Disks)
  - RAID is putting a whole bunch of disks together and they act as one disk.
  - Raid 0: Striped, No redundancy, good performance
  - Raid 1: Mirrored, Redundancy
  - Raid 5: Good for reads, bad for writes, AWS does not recommend putting raid 5 on EBS
  - Raid 10: Striped mirrored, Good redundancy and Good performance
