//
//  ViewController.swift
//  calculadora
//
//  Created by roger on 10/03/25.
//

import UIKit

class ViewController: UIViewController {


    @IBOutlet weak var IMCLabel: UILabel!
    
    @IBOutlet weak var Peso: UITextField!
    
    @IBOutlet weak var Altura: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        view.endEditing(true)
    }
    
    @IBAction func calcular(_ sender: Any) {
        let peso: Float = Float(Peso.text!)!
        let altura: Float = Float(Altura.text!)!
        IMCLabel.text = "\(peso/(altura*altura))"
    }
    
    @IBAction func limpiar(_ sender: Any) {
        IMCLabel.text = "0"
        Peso.text = ""
        Altura.text = ""
    }
    
    
}
