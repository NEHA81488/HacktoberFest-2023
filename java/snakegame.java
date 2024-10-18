import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Random;

public class SimpleSnakeGame extends JPanel implements ActionListener {

    private final int SIZE = 300;
    private final int DOT_SIZE = 10;
    private final int ALL_DOTS = 900;
    private final int RAND_POS = 29;
    private final int DELAY = 140;

    private final int[] x = new int[ALL_DOTS];
    private final int[] y = new int[ALL_DOTS];

    private int bodyLength;
    private int appleX;
    private int appleY;

    private boolean left = false;
    private boolean right = true;
    private boolean up = false;
    private boolean down = false;
    private boolean inGame = true;

    private Timer timer;
    private Random random;

    public SimpleSnakeGame() {
        setBackground(Color.black);
        setPreferredSize(new Dimension(SIZE, SIZE));
        setFocusable(true);
        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                int key = e.getKeyCode();
                if (key == KeyEvent.VK_LEFT && !right) { left = true; up = down = false; }
                if (key == KeyEvent.VK_RIGHT && !left) { right = true; up = down = false; }
                if (key == KeyEvent.VK_UP && !down) { up = true; right = left = false; }
                if (key == KeyEvent.VK_DOWN && !up) { down = true; right = left = false; }
            }
        });

        initGame();
    }

    private void initGame() {
        bodyLength = 3;
        for (int i = 0; i < bodyLength; i++) {
            x[i] = 50 - i * DOT_SIZE;
            y[i] = 50;
        }

        random = new Random();
        locateApple();

        timer = new Timer(DELAY, this);
        timer.start();
    }

    private void locateApple() {
        appleX = random.nextInt(RAND_POS) * DOT_SIZE;
        appleY = random.nextInt(RAND_POS) * DOT_SIZE;
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (inGame) {
            g.setColor(Color.red);
            g.fillRect(appleX, appleY, DOT_SIZE, DOT_SIZE);

            for (int i = 0; i < bodyLength; i++) {
                if (i == 0) g.setColor(Color.green);
                else g.setColor(Color.white);
                g.fillRect(x[i], y[i], DOT_SIZE, DOT_SIZE);
            }
        } else {
            gameOver(g);
        }
    }

    private void gameOver(Graphics g) {
        String msg = "Game Over";
        g.setColor(Color.white);
        g.drawString(msg, SIZE / 2 - 30, SIZE / 2);
    }

    private void move() {
        for (int i = bodyLength; i > 0; i--) {
            x[i] = x[i - 1];
            y[i] = y[i - 1];
        }

        if (left) x[0] -= DOT_SIZE;
        if (right) x[0] += DOT_SIZE;
        if (up) y[0] -= DOT_SIZE;
        if (down) y[0] += DOT_SIZE;
    }

    private void checkApple() {
        if (x[0] == appleX && y[0] == appleY) {
            bodyLength++;
            locateApple();
        }
    }

    private void checkCollision() {
        for (int i = bodyLength; i > 0; i--) {
            if (x[0] == x[i] && y[0] == y[i]) {
                inGame = false;
            }
        }
        if (x[0] < 0 || x[0] >= SIZE || y[0] < 0 || y[0] >= SIZE) {
            inGame = false;
        }

        if (!inGame) timer.stop();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (inGame) {
            checkApple();
            checkCollision();
            move();
        }
        repaint();
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Snake Game");
        SimpleSnakeGame game = new SimpleSnakeGame();
        frame.add(game);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
