package assignment_2b;

import java.util.Scanner;

public class TwoWheeler implements MotorCycle, Cycle {
    public int speed = 0;
    public int time = 0;
    public int total_distance = 0;

    @Override
    public void speed() {
        System.out.println(total_distance / time);
    }

    @Override
    public void totalDistance() {
        System.out.println(speed * time);
    }
}
