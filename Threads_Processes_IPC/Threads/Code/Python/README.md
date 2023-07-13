**Create Threads using Threading Library**

**Thread.run():**
- This is inbuilt method of the Thread class of the threading module in Python.
- This method is used to represent a thread's activity. It calls the method expressed as the target argument in the Thread object along with the positional and keyword arguments taken from the args and kwargs arguments, respectively. This method can also be overridden in the subclass.
```py
import threading, zipfile

class AsyncZip(threading.Thread):
    def __init__(self, infile, outfile):              # Constructor
        threading.Thread.__init__(self)
        self.infile = infile
        self.outfile = outfile

    def run(self):
        f = zipfile.ZipFile(self.outfile, 'w', zipfile.ZIP_DEFLATED)
        f.write(self.infile)
        f.close()
        print('Finished background zip of:', self.infile)

background = AsyncZip('mydata.txt', 'myarchive.zip')
background.start()
print('The main program continues to run in foreground.')

background.join()    # Wait for the background task to finish
print('Main program waited until background was done.')
```
