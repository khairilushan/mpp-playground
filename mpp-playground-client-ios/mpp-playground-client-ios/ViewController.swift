//
//  ViewController.swift
//  mpp-playground-client-ios
//
//  Created by Khairil Ushan on 8/4/18.
//  Copyright © 2018 Khairil Ushan. All rights reserved.
//

import UIKit
import Mpp

final class ViewController: UIViewController {

    @IBOutlet weak var searchEditText: UITextField!
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var searchButton: UIButton!
    @IBOutlet weak var indicatorView: UIActivityIndicatorView!
    
    private var projects: [ProjectItemViewModel] = []
    private lazy var viewModel: SearchProjectViewModelInputs = {
        return SearchProjectViewModelImpl(outputs: self)
    }()

    override func viewDidLoad() {
        super.viewDidLoad()
        setupView()
        viewModel.onViewCreated()
    }

    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        viewModel.onViewDestroyed()
    }

    @IBAction func onSearchButtonClicked(_ sender: UIButton) {
        viewModel.onSearchButtonClicked()
    }

    @IBAction func onSearchTextChanged(_ sender: UITextField) {
        viewModel.onSearchTextFieldChanged(text: sender.text ?? "")
    }

    private func setupView() {
        title = "MPP Playground"
        let textAttributes = [NSAttributedStringKey.foregroundColor: UIColor.white]
        navigationController?.navigationBar.titleTextAttributes = textAttributes
        navigationController?.navigationBar.isTranslucent = false
        navigationController?.navigationBar.barTintColor = UIColor(
            red: 0.15,
            green: 0.25,
            blue: 0.52,
            alpha: 1
        )
        tableView.register(
            ProjectTableViewCell.nib,
            forCellReuseIdentifier: ProjectTableViewCell.identifier
        )
    }

    private func reloadData(_ projects: [ProjectItemViewModel]) {
        self.projects = projects
        tableView.reloadData()
    }
}

extension ViewController : UITableViewDelegate {
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(for: indexPath) as ProjectTableViewCell
        cell.bind(with: projects[indexPath.row])
        return cell
    }

    func tableView(
        _ tableView: UITableView,
        estimatedHeightForRowAt indexPath: IndexPath
        ) -> CGFloat {
        return ProjectTableViewCell.height
    }

    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return UITableViewAutomaticDimension
    }
}

extension ViewController : UITableViewDataSource {
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return projects.count
    }
}

extension ViewController : SearchProjectViewModelOutputs {
    func shouldDismissKeyboard() {
        searchEditText.resignFirstResponder()
    }

    func showErrorMessage(message: String) {
        let alert = UIAlertController(title: "Error", message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
        present(alert, animated: true, completion: nil)
    }

    func startLoading() {
        indicatorView.isHidden = false
    }

    func finishLoading() {
        indicatorView.isHidden = true
    }

    func shouldUpdateData(data: [ProjectItemViewModel]) {
        reloadData(data)
    }
}

extension UITableView {
    func dequeueReusableCell<T: UITableViewCell>(for indexPath: IndexPath) -> T where T: ReusableCell {
        return dequeueReusableCell(withIdentifier: T.identifier, for: indexPath) as! T
    }
}

