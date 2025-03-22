//
//  ViewController.swift
//  calculadora
//
//  Created by roger on 10/03/25.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        view.endEditing(true)
    }

    @IBAction func calcular(_ sender: Any) {
        print("calculanding")
    }

    @IBAction func limpiar(_ sender: Any) {
        print("limpianding")
    }
}
