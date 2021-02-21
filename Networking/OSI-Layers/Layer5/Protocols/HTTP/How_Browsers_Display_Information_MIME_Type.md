## How Browser Display Information?
> Using MIME Type
- When a server returns a page, it also returns some additional information(MIME type) about the page. MIME type tells how browser should display the page.
- A page may consist of a video(MPEG format), a document(PDF format), a photograph(JPEG format) or any one of hundreds of other file types.
  - *1.* Pages of type text/html are just displayed directly, as are pages in a few other built-in types. 
  - *2.* For MIME type=pdf/flash/mpeg/jpg browser uses plugins or helper applications to display the content.

- **Plug-in?** is a third-party module that is installed as an extension to the browser which helps to display/process the contents. Eg: PDF reader. Browsers usually come preloaded with popular plug-ins.
- **Helper application?**
  - This is large program, running as a separate process. Eg: Microsoft Word or PowerPoint. If URL points to a PowerPoint file, and when the user clicks on it, PowerPoint is automatically started and handed the content to be displayed. Browsers can be configured to handle a virtually unlimited number of document types with no changes to themselves.
