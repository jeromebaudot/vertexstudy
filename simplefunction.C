void simplefunction()
{
    // x = momentum (GeV/c)
    // f = difference (m) = R sqrt(1- r*r/(R*R))
    // R = x/ 0.3 B  wit B = 1.5 T
    // parameter [0] = r (m)

    

    TF1 *f = new TF1("f", "x/(0.3*1.5)*(1 - sqrt(1- pow( ([0]*0.3*1.5)/x ,2 ) ) ) ", 0, 3);

    f->SetParameter(0, 12.e-3);
    f->SetLineColor(2);
    f->Draw();
    TLine *line = new TLine(0, 0.012,3, 0.012);
    line->SetLineColor(2);
    line->Draw();

    /*
 f->SetParameter(0, .5e-2);
 f->SetLineColor(2);
 f->DrawClone("same");
*/

    f->GetHistogram()->SetXTitle("momentum (GeV/c)");
    f->GetHistogram()->SetYTitle("#delta (m)");
    f->GetHistogram()->SetTitle("Track divergence");

    gPad->SetGrid(1, 1);
}
