class Timer {
private:
    double speed;

public:
    // Constructeur
    Timer(double numerator) : speed(numerator) {}

    // Méthode pour obtenir la vitesse
    double getSpeed() const {
        return speed;
    }
};
