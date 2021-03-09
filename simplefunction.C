void simplefunction()
{
    // x = momentum (GeV/c)
    // f = difference (m) = R sqrt(1- r*r/(R*R))
    // R = x / 0.3 B  wit B = 1.5 T
    // parameter [0] = r (m)

    TH1F *h = new TH1F( "h","Track divergence; Transverse Momentum (GeV/c); #delta (m)", 100, 0, 1);
    h->SetMaximum(.003); 
    h->Draw();

    TF1 *f = new TF1("f", "x/(0.3*1.5)*(1 - sqrt(1 - pow(([0]*0.3*1.5)/x, 2))) ", 0, 1);

    f->SetParameter(0, 12.e-3);
    f->SetLineColor(2);
    f->DrawClone("same");
    
    f->SetParameter(0, 5.e-3);
    f->SetLineColor(3);
    f->DrawClone("same");

    gPad->SetGrid(1, 1);
    gPad->SetLogx();
    gPad->SetLogy();
}
