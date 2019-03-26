package servlets;

import java.io.File;
import java.io.IOException;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.codehaus.jackson.map.ObjectMapper;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

import objects.Stand;
import objects.TimeStats;


public class JSONconverter {
	public static void main(String[] args) {  
		JSONObject sampleObject = new JSONObject();
	   
		Stand s = new Stand(1,1234);

		sampleObject.put("stand", s.getScore());

		List<TimeStats> l = s.getHistorikk();
		
		sampleObject.put("coordinates", l);

		
	    JSONArray x = new JSONArray();
	    JSONArray y = new JSONArray();
	    for(int i = 0 ; i<l.size();i++) {
	    x.add(l.get(i).getTime().getTime());
	    y.add(l.get(i).getScore());
	    }
	    sampleObject.put("x", x);
	    sampleObject.put("y", y); 
	    System.out.println(sampleObject);
	}
	
	public JSONObject convert(Stand s) {  
		JSONObject object = new JSONObject();
	   
		object.put("stand", s.getId());
		List<TimeStats> l = s.getHistorikk();
		
	    JSONArray x = new JSONArray();
	    JSONArray y = new JSONArray();
	    for(int i = 0 ; i<l.size();i++) {
	    x.add(l.get(i).getTime().getTime());
	    y.add(l.get(i).getScore());
	    }
	    object.put("x", x);
	    object.put("y", y); 
	    return object;
	}
	
}
