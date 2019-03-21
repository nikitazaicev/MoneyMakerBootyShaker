package objects;

import org.json.simple.JSONObject;

public class JSONconverter {
	public static void main(String[] args) {
	      JSONObject obj = new JSONObject();
	      Stand stand= new Stand("123",12321);
	      stand.getHistorikk().add(new TimeStats());

	      obj.put(stand, stand.getHistorikk());
	      System.out.print(obj);
	   }
	
}
