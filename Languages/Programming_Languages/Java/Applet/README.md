Applet

### Applet
- Java Code which can execute under the control of a browser is called an applet.
- The environment of the applet is known as the context of the applet.
- Lifecycle of an applet
|state|Meaning|Method|
|---|---|---|
|init|When user opens webpage for 1st time|init()|
|start|After init when applet recieves focus|start()|
|stop|When applet looses focus|stop()|
|Destroy|When user moves to other page|destroy()|

### Examples
#### 
```java
//test.java
import java.awt.Graphics;
import java.awt.Color;
import java.applet.*;
public class test extends Applet {
  public void paint(Graphics g) {
    g.drawString("Hello world! ",20,20);
 }
}
```
