package org.howmuch;

import java.awt.*;

public class Colors {

    static Boolean DarkMode = false;

    // Light mode Colors
    static Color light_bgColor = new Color(255, 227, 227);
    static Color light_primaryColor = new Color(38, 42, 83);
    static Color light_secondaryColor = new Color(255, 160, 160);
    static Color light_accentColor = new Color(27, 153, 139);

    // Dark Mode Colors
    static Color dark_bg_color = new Color(31, 29, 54);
    static Color dark_primaryColor = new Color(233, 166, 166);
    static Color dark_secondaryColor = new Color(175, 89, 159);
    static Color dark_accentColor = new Color(27, 153, 139);

    static Color bgColor = DarkMode ? dark_bg_color : light_bgColor;
    static Color primaryColor = DarkMode ? dark_primaryColor : light_primaryColor;
    static Color secondaryColor = DarkMode ? dark_secondaryColor : light_secondaryColor;
    static Color accentColor = DarkMode ? dark_accentColor : light_accentColor;

    public static void reassignColors() {
        bgColor = DarkMode ? dark_bg_color : light_bgColor;
        primaryColor = DarkMode ? dark_primaryColor : light_primaryColor;
        secondaryColor = DarkMode ? dark_secondaryColor : light_secondaryColor;
        accentColor = DarkMode ? dark_accentColor : light_accentColor;
    }
}
