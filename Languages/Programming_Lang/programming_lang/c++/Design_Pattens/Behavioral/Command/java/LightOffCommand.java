public class LightOffCommand implements Command
{ 
        Light l;

        public LightOffCommand(Light k)
        {
                this.l = k;
        }

        public void execute()
        {
                l.off();
        }
}
