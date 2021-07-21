- [Creating msi package](#create)

### Create msi package
```c
New > MSI Installer (give name) > Create Subdirectory under projects 2020

//Edit the following
Installation Information
  General Information
    Product Name
    Product Version
    Publisher/Company Name
    INSTALLDIR
Application Data
  Files and Folders
    Destination Computer
      ProgramFilesFolder
        Company_name  //Edit
          Installer_name  //Edit
            //Drag and drop installer files from above
          Documentation //Create this
            //Drag and drop README from above
System Configuration
  Registry
    HKEY_LOCAL_MACHINE
      Software                              //Add new key
        [Manufacturer]                      //Look at this property in installer
          [ProductName]                     //Look at this property in installer
            New String value
              Version[ProductVersion]
Build     //Build the installer
Run       //Run to test the installer
```
