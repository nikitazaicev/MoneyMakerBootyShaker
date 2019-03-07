package objects;

import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.PersistenceContext;


@Stateless
public class StandEAO {

	@PersistenceContext(name = "expo")
    private EntityManager em;
	
	public Stand getStand(String id) {
		return em.find(Stand.class, id);
	}

}
