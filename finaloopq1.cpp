#include <iostream>
using namespace std;
class PowerSource
{
    string plantID;

public:
    virtual void generateEnergy() { cout << "Simulating Energy generation " << endl; }
};
class TidalPlant : public PowerSource
{
protected:
    float tidalOutput;
    float waveEfficiency;

public:
    TidalPlant(float output, float efficiency)
    {
        tidalOutput = output;
        waveEfficiency = efficiency;
    }
    void generateEnergy() override
    {
        cout << "Tidal Output: " << tidalOutput << endl;
        cout << "Wave Efficiency: " << waveEfficiency << endl;
    }
    friend TidalPlant adjustTidal(TidalPlant t);
    friend class MaintenanceSystem;
};
class GeothermalPlant : public PowerSource
{
protected:
    float geoOutput;
    float steamEfficiency;

public:
    GeothermalPlant(float gout, float steameff)
    {
        geoOutput = gout;
        steamEfficiency = steameff;
    }
    void generateEnergy() override
    {
        cout << "Geothermal Energy Output: " << geoOutput << endl;
        cout << "Steam Efficiency: " << steamEfficiency << endl;
    }
    friend class MaintenanceSystem;
};
class HybridPlant : public TidalPlant, public GeothermalPlant
{
    int output;

public:
    HybridPlant(float tOutput, float tEff, float gOutput, float gEff)
        : TidalPlant(tOutput, tEff), GeothermalPlant(gOutput, gEff) {}
    void generateEnergy() override
    {
        output = geoOutput + tidalOutput;
        cout<<"The combine output of both plants is "<<output<<endl;
    }
    friend class MaintenanceSystem;
};
class MaintenanceSystem
{
public:
    void inspectTidal(const TidalPlant &tidal)
    {
        cout << "Tidal Output: " << tidal.tidalOutput << endl;
        cout << "Wave Efficiency: " << tidal.waveEfficiency << endl;
    }
    void inspectGeothermal(const GeothermalPlant &Geo)
    {
        cout << "GeoThermal Output: " << Geo.geoOutput << endl;
        cout << "Steam Efficiency: " << Geo.steamEfficiency << endl;
    }
    TidalPlant adjustTidal(TidalPlant t, int newTidal)
    {
        newTidal = t.tidalOutput;
        cout << "New Tidal Output: " << t.tidalOutput << endl;
    }
    GeothermalPlant adjustGeothermal(GeothermalPlant Geo, float newGeo)
    {
        newGeo = Geo.geoOutput;
        cout << "New Geo Thermal Energy Output: " << Geo.geoOutput << endl;
    }
};
int main()
{
    PowerSource ps;
    ps.generateEnergy();
    TidalPlant tp(24000, 2.5);
    tp.generateEnergy();
    cout << "\n=== Geothermal Plant ===\n";
    GeothermalPlant geo(210.2, 75.8);
    geo.generateEnergy();

    cout << "\n=== Hybrid Plant ===\n";
    HybridPlant hybrid(100.0, 80.0, 150.0, 70.0);
    hybrid.generateEnergy();

    cout << "\n=== Maintenance Inspection ===\n";
    MaintenanceSystem ms;
    ms.inspectTidal(tp);
    ms.inspectGeothermal(geo);

    cout << "\n=== Calibration Functions ===\n";
    ms.adjustTidal(tp, 180.0);
    ms.adjustGeothermal(geo, 230.0);

    cout << "\n=== Re-Inspection After Calibration ===\n";
    ms.inspectTidal(tp);
    ms.inspectGeothermal(geo);
}