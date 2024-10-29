public class MainCharacecter 
{
    public int hp=100;
    public int defence=5;
    public int attack=5;

    public void battle(Enemy enemy)
    {
        while (this.hp > 0 && enemy.hp >0)
        {
           enemy.hp= enemy.hp - this.attack + enemy.defence;
            this.hp= this.hp - enemy.attack + this.defence;
            Console.WriteLine ($"Player HP: {this.hp}\n Enemy HP: {enemy.hp}");
        }
        if (this.hp > 0)
        {
            Console.WriteLine("Player Wins");
        }
        else
        {
            Console.WriteLine("Enemy Wins");
        }
    }
}
public class Enemy
{
    public int hp=75;
    public int defence=2;
    public int attack=7;


static void Main(string[] args)
{
    MainCharacecter SirLancelot = new MainCharacecter();
    Enemy BoblibGoblin = new Enemy();
    SirLancelot.battle(BoblibGoblin);
}
}