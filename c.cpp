public abstract class Application{
    private String fileName;
    private boolean canReald - false;
    private boolean Result - false;
    public Open(String filename){
		canRead = checkFile(fileName);
        if(canRead == false) return false;
        result = process(fileName);
        return result;
    }
    private boolean process(String fileName){retrun false;}
    private boolean checkFile(String fileName){retrun false;}


}

public class Xls extends Application{
    private String fileName;
}


public class Doc extends Application{
    private boolean checkFile(String fileName){retrun false;}
}