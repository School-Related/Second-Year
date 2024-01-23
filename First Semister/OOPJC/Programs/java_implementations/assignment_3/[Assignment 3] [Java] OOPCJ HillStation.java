package assignment_3;

abstract public class HillStation {
    abstract public void location(); // Pure Virtual Function.

    abstract public void famousfor();
}

class Manali extends HillStation {
    @Override
    public void location() {
        System.out.println("Manali in Himachal Pradesh");
    }

    @Override
    public void famousfor() {
        System.out.println(
                "Manali is a high-altitude Himalayan resort town in India's northern Himachal Pradesh state. It has a reputation as a backpacking center. Set on the Beas River, it's a gateway for skiing in the Solang Valley and trekking in Parvati Valley. It's also a jumping-off point for paragliding, rafting and mountaineering in the Pir Panjal mountains, home to 4,000m-high Rohtang Pass.");
    }
}

class Shimla extends HillStation {
    @Override
    public void location() {
        System.out.println("Shimla is in Himachal Pradesh");
    }

    @Override
    public void famousfor() {
        System.out.println(
                "The town is famous for pleasant walking experiences on hillsides surrounded by pine and oak forests. This capital city of Himachal Pradesh is famous for The Mall, ridge, and toy train. With colonial style buildings, the town has relics of ancient past that lend it a distinct look.");
    }
}

class Mahabaleshwar extends HillStation {
    @Override
    public void location() {
        System.out.println("Mahabaleshwar is in Maharashtra");
    }

    @Override
    public void famousfor() {
        System.out.println(
                "Mahabaleshwar is a hill station in India's forested Western Ghats range, south of Mumbai. It features several elevated viewing points, such as Arthur's Seat. West of here is centuries-old Pratapgad Fort, perched atop a mountain spur. East, Lingmala Waterfall tumbles off a sheer cliff. Colorful boats dot Venna Lake, while 5 rivers meet at Panch Ganga Temple to the north.");
    }
}